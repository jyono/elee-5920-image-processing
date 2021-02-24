#include <iostream>
#include "mexAdapter.hpp"
// Boiler Plate and working example of matlab MEX C++/engine APIs
// This is no the same
class MexFunction : public matlab::mex::Function {
    void operator()(matlab::mex::ArgumentList outputs, matlab::mex::ArgumentList inputs) override {
        std::cout << "HEY";
        // Get instance of Matlab Engine API. Equivalent to the engine API's startEngine();
        const std::shared_ptr<matlab::engine::MATLABEngine> &matlabPtr = getEngine();

        // Matlab Array factory
        matlab::data::ArrayFactory factory;

        // Validate arguments
        checkArguments(outputs, inputs, matlabPtr, factory);
        std::cout << "Argument Check Complete" << "\n";

        // Implement function
        std::vector<matlab::data::Array> args(inputs.begin(), inputs.end());
        matlab::data::Array result;

        // Call matlab engine sqrt function
        result = matlabPtr->feval(u"sqrt", args);

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
