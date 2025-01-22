//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "GoatTestApp.h"
#include "GoatApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
GoatTestApp::validParams()
{
  InputParameters params = GoatApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

GoatTestApp::GoatTestApp(InputParameters parameters) : MooseApp(parameters)
{
  GoatTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

GoatTestApp::~GoatTestApp() {}

void
GoatTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  GoatApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"GoatTestApp"});
    Registry::registerActionsTo(af, {"GoatTestApp"});
  }
}

void
GoatTestApp::registerApps()
{
  registerApp(GoatApp);
  registerApp(GoatTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
GoatTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  GoatTestApp::registerAll(f, af, s);
}
extern "C" void
GoatTestApp__registerApps()
{
  GoatTestApp::registerApps();
}
