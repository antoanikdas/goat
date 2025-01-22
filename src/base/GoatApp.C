#include "GoatApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
GoatApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

GoatApp::GoatApp(InputParameters parameters) : MooseApp(parameters)
{
  GoatApp::registerAll(_factory, _action_factory, _syntax);
}

GoatApp::~GoatApp() {}

void
GoatApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAllObjects<GoatApp>(f, af, syntax);
  Registry::registerObjectsTo(f, {"GoatApp"});
  Registry::registerActionsTo(af, {"GoatApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
GoatApp::registerApps()
{
  registerApp(GoatApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
GoatApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  GoatApp::registerAll(f, af, s);
}
extern "C" void
GoatApp__registerApps()
{
  GoatApp::registerApps();
}
