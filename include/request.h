#ifndef REQUEST_H
#define REQUEST_H

#include "product_type.h"
#include "operation_type.h"

struct Request {
  Request(ProductType product, OperationType operation)
      : product_(product), operation_(operation) {}
  ProductType product_;
  OperationType operation_;
};

#endif  // REQUEST_H
