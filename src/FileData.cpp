//
// Created by stefanspitse on 6/27/26.
//
#include <QtNodes/NodeData>

class FileData : public QtNodes::NodeData
{
    public:
        FileData(double value = 0.0) : _value(value) {}

        QtNodes::NodeDataType type() const override {
                return {"number", "Number"};
        }
    private:
        double _value;
}