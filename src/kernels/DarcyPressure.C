#include "DarcyPressure.h"

registerMooseObject("GoatApp", DarcyPressure);

InputParameters
DarcyPressure::validParams()
{
    InputParameters params = ADKernelGrad::validParams();
    params.addClassDescription("Compute the diffusion term for Darcy pressure ($p$) equation: "
                             "$-\\nabla \\cdot \\frac{\\mathbf{K}}{\\mu} \\nabla p = 0$");
    
    return params;
}

DarcyPressure::DarcyPressure(const InputParameters & parameters)
    : ADKernelGrad(parameters),

    // Set the permeability and viscosity values
    _permeability(0.8451e-09),
    _viscosity(7.98e-04)
{
}

ADRealVectorValue
DarcyPressure::precomputeQpResidual()
{
    return (_permeability / _viscosity) * _grad_u[_qp];
}
