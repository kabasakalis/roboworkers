#include "products/product.h"

Product::Type Product::get_type() const { return type_; }

virtual std::string Product::get_name() const { return name_; }


