#pragma once

#include "Material.hpp"

class Covering : public Material {
    public:
        Covering(const std::string &name_, double price_, double width_);
        double get_width() const { return width; }
        void print() const;

    private:
        double width; // meter
};