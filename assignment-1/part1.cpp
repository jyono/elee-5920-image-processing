#include <iostream>
//#include "mex.hpp" Not sure i even need this
#include "mexAdapter.hpp"

//using namespace matlab::data;
//using matlab::mex::ArgumentList;

class MexFunction : public matlab::mex::Function {
    void operator()(matlab::mex::ArgumentList outputs, matlab::mex::ArgumentList inputs) override {
        // Get instance of Matlab Engine API. Equivalent to the engine API's startEngine();
        const std::shared_ptr<matlab::engine::MATLABEngine> &matlabPtr = getEngine();
        // Matlab Array factory
        matlab::data::ArrayFactory factory;

        // Validate arguments
        checkArguments(outputs, inputs, matlabPtr, factory);
        std::cout << "Argument Check Complete" << "\n";

        // Implement function
        std::cout << "<< 1" << "\n";
        matlab::data::TypedArray<double> inputValues(std::move(inputs[0]));


        std::initializer_list<double> data();
        for(double elem : inputValues){

        }

        std::vector<matlab::data::Array> args({factory.createArray<double>({inputs[0].getDimensions()}, data)});
//        std::vector<matlab::data::Array> args({factory.createArray<double>(inputs[0].getDimensions(), inputValues)});
        matlab::data::Array result;

        std::cout << "<< 2" << "\n";
        result = matlabPtr->feval(std::string("sqrt"), args);
        std::cout << "<< 3" << "\n";
        // Assign outputs
        outputs[0] = result;
    }

    void checkArguments(matlab::mex::ArgumentList outputs,
                        matlab::mex::ArgumentList inputs,
                        const std::shared_ptr<matlab::engine::MATLABEngine> &matlabPtr,
                        matlab::data::ArrayFactory &factory) {
        if (inputs[0].getType() != matlab::data::ArrayType::DOUBLE ||
            inputs[0].getType() == matlab::data::ArrayType::COMPLEX_DOUBLE) {
            matlabPtr->feval(u"error", 0,
                             std::vector<matlab::data::Array>({factory.createScalar("Input must be double array")}));
        }

        if (outputs.size() > 1) {
            matlabPtr->feval(u"error", 0,
                             std::vector<matlab::data::Array>({factory.createScalar("Only one output is returned")}));
        }
    }
};
