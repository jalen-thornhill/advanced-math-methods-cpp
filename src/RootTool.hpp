#pragma once

class RootTool
{
    public:
        double evaluateFunction( int choice, double x);
        
        
        double evaluateDerivative(int choice, double x);

        double linearInterpolation(int functionChoice, double a, double b);

        double newtonRaphson(int functionChoice, double startX, int iterations);

        void rootMenu();
};