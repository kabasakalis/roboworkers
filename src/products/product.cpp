#include "products/product.h"

Product::Type Product::get_type() const { return type_; }

std::string Product::get_name() const { return name_; }

int Product::getWorkloadMultiplier() const { return workloadMultiplier_; }

