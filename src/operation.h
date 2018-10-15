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
        INBOUND, DELIVER
    };
    Operation(Type type, const Product &product) :
            product_(product), type_(type) {
        switch (type) {
            //LIFT->MOVE->PUT_DOWN->MOVE
            case Type::INBOUND :
                tasks.emplace_back(Lift(id, product_));
                tasks.emplace_back(Move(id, product_));
                tasks.emplace_back(PutDown(id, product_));
                tasks.emplace_back(Move(id, product_));
                break;
            case Type::DELIVER:
                //MOVE-LIFT-MOVE-PACKAGE-MOVE-PUT_DOWN-MOVE
                tasks.emplace_back(Move(id, product_));
                tasks.emplace_back(Lift(id, product_));
                tasks.emplace_back(Move(id, product_));
                tasks.emplace_back(Package(id, product_));
                tasks.emplace_back(Move(id, product_));
                tasks.emplace_back(PutDown(id, product_));
                tasks.emplace_back(Move(id, product_));
                break;
        }
    }

    void process() {
        set_start_time();
        for (auto task : tasks) task.execute();
        set_finish_time();
        logOperation(id, creation_time, start_time, finish_time);
    };


protected:
    Product product_;
    int type_;
    std::deque<Task> tasks;
};


#endif //ROBOWORKERS_OPERATION_H
