/**
 * @file request.h
 *
 * @brief Request class
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

#ifndef REQUEST_H
#define REQUEST_H

#include "products/product.h"
#include "operations/operation.h"

struct Request {

    /**
     * Default Constructor
     */
    Request();

    /**
     *  @brief Constructor
     *
     *  @details Constructs a request for a product of type product_type
     *           which will be handled by an operation of type operation_type
     *
     * @param product_type
     * @param operation_type
     */
    Request(Product::Type product_type, Operation::Type operation_type);

    Operation& get_operation() { return operation_; };
private:
    /**
     * @brief Construct a product object from the type
     *
     * @param product_type the product type enum
     * @return             the product
     */
    Product get_product_from_Type(Product::Type product_type);

    Operation operation_;
    Product::Type product_type_;
    Operation::Type operation_type_;
};

#endif  // REQUEST_H
