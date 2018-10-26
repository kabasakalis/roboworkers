/**
 * @file request.cpp
 *
 * @brief Request class, definition
 *
 * @version 1.0
 *
 * @author Spiros Kabasakalis
 * Contact: kabasakalis@gmail.com
 *
 * @copyright 2018 Spiros Kabasakalis
 * This code is licensed under MIT license (see LICENSE for details)
 *
 */

#include "request.h"


Request::Request(Product::Type product_type, Operation::Type operation_type)
        : product_type_(product_type),
          operation_type_(operation_type),
          operation_(std::move(Operation(operation_type, get_product_from_Type(product_type)))) {}

Request::Request() :
        product_type_(Product::Type::NONE),
        operation_type_(Operation::Type::NONE),
        operation_(std::move(Operation(Operation::Type::NONE, get_product_from_Type(Product::Type::NONE)))) {}


Product Request::get_product_from_Type(Product::Type product_type) {
    switch (product_type) {
        case Product::Type::SOFA : {
            return std::move(Sofa());
            break;
        }
        case Product::Type::CHAIR: {
            return std::move(Chair());
            break;
        }
        case Product::Type::NONE: {
            return std::move(Product());
            break;
        }
        default: {
            throw std::runtime_error("Unknown operation type.");
        };
    }
}
