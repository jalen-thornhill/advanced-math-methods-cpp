#pragma once
#include <string>

// I am grouping preset formulas, derivative evaluation, and root approximation methods in this class.
class RootTool
{
    public:
        // I am declaring methods that evaluate a chosen function and its stored derivative formula.
        double evaluateFunction( int choice, double x);
        
        
        double evaluateDerivative(int choice, double x);

        // I am declaring a single straight-line root estimate based on two supplied endpoints.
        double linearInterpolation(int functionChoice, double a, double b);

        // I am declaring repeated Newton updates from a starting estimate.
        double newtonRaphson(int functionChoice, double startX, int iterations);

        // I am declaring the interactive menu for these root approximation tools.
        void rootMenu(std::string& lastResult);
};
