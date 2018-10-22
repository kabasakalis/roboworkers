#ifndef REQUEST_H
#define REQUEST_H

#include "product.h"
#include "operation.h"

struct Request {
    Request(Product::Type product_type, Operation::Type operation_type)
            : product_type_(product_type),
              operation_type_(operation_type)
//              operation_(Operation(operation_type, get_product_from_Type(product_type)))
    {

        operation_ = std::move(Operation(operation_type, get_product_from_Type(product_type)));

    };


    Request() :
            product_type_(Product::Type::NONE),
            operation_type_(Operation::Type::NONE)
//      operation_(Operation(Operation::Type::INBOUND, get_product_from_Type(Product::Type::CHAIR )))
    {


        operation_ = std::move(Operation(Operation::Type::NONE, Product()));

    };


    Operation &get_operation() { return operation_; };
private:
    Product get_product_from_Type(Product::Type product_type) {
        switch (product_type) {
            case Product::Type::SOFA : {
                Sofa sofa;
                return sofa;
                break;
            }
            case Product::Type::CHAIR: {
                Chair chair;
                return chair;
                break;
            }
            case Product::Type::NONE: {
                Product product;
                return product;
                break;
            }

            default: {
                throw std::runtime_error("Unknown operation type.");
            };
        }
    }

    Operation operation_;
    Product::Type product_type_;
    Operation::Type operation_type_;
};


#endif  // REQUEST_H
