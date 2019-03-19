#include "main.h"


int main(int argc, char **argv)
{
	fl::Engine* engine = fl::FisImporter().fromFile("MatL.fis");

	engine->getInputVariable(0)->setValue(2);
	engine->getInputVariable(1)->setValue(-1);

	engine->process();

	fl::OutputVariable* output = engine->getOutputVariable(0);

	printf("%f\n", output->getValue());

	system("PAUSE");
}

