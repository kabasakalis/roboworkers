#ifndef ROBOWORKERS_OPERATION_H
#define ROBOWORKERS_OPERATION_H


#include <utilities.h>
#include <product.h>
#include <timestampable.h>
#include <deque>
#include <lift.h>
#include <move.h>
#include <putdown.h>
#include <package.h>

class Operation : public Identifiable, Timestampable {
public:
    enum Type {
        NONE, INBOUND, DELIVER
    };


    Operation() : product_(Product()), type_(Type::NONE)  {};

    Operation(Type type, Product product ) :
            product_(product), type_(type) {

        switch (type) {
            //LIFT->MOVE->PUT_DOWN->MOVE
            case Type::INBOUND :
                tasks_.emplace_back(std::shared_ptr<Task>(new Lift(id, product_)));
                tasks_.emplace_back(std::unique_ptr<Task>(new Move(id, product_)));
                tasks_.emplace_back(std::unique_ptr<Task>(new PutDown(id, product_)));
                tasks_.emplace_back(std::unique_ptr<Task>(new Move(id, product_)));
                break;
            case Type::DELIVER:
                //MOVE-LIFT-MOVE-PACKAGE-MOVE-PUT_DOWN-MOVE
                tasks_.emplace_back(std::shared_ptr<Task>(new Move(id, product_)));
                tasks_.emplace_back(std::unique_ptr<Task>(new Lift(id, product_)));
                tasks_.emplace_back(std::unique_ptr<Task>(new Move(id, product_)));
                tasks_.emplace_back(std::unique_ptr<Task>(new Package(id, product_)));
                tasks_.emplace_back(std::unique_ptr<Task>(new Move(id, product_)));
                tasks_.emplace_back(std::unique_ptr<Task>(new PutDown(id, product_)));
                tasks_.emplace_back(std::unique_ptr<Task>(new Move(id, product_)));
                break;
            case Type::NONE:
               break;
            default:
                throw std::runtime_error("Unknown operation type.");
        }

    }


    void process() {
        set_start_time();
        for (auto& task : tasks_) task -> execute();
        set_finish_time();
        logOperation(id, creation_time, start_time, finish_time);
    };


private:
    Product product_;
    int type_;
    std::vector<std::shared_ptr<Task>> tasks_;
};

#endif //ROBOWORKERS_OPERATION_H
