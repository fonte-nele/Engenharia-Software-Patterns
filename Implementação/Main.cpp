#include "ModelHandle.h"
#include <assert.h>
#include <cmath>
#include <iostream>

using namespace std;

class Exponencial : public FlowHandle
{
	public:
		Exponencial(std::string id, System* source, System* target, double flow_rate) : FlowHandle(id, source, target, flow_rate){ }
		double execute()
		{
			System *source = this->getSource();
			
			return this->getFlowRate() * source->getValue();
		}
};

class Logistico : public FlowHandle
{
	public:
		Logistico(std::string id, System* source, System* target, double flow_rate) : FlowHandle(id, source, target, flow_rate){ }
		double execute()
		{
			System *source = this->getSource();
			
			return this->getFlowRate() * (source->getValue()) * (1 - (source->getValue()) / source->getMaxValue());
		}
};

void ModelExponencial()
{
	double expected[2] = {36.6032, 63.3968};

	Model* exponencial = Model::createModel("Exponencial");

	System* pop1 = exponencial->createSystem("pop1", 100.0, 70.0);
	System* pop2 = exponencial->createSystem("pop2", 0.0, 70.0);

	exponencial->createFlow<Exponencial>("exponencial", pop1, pop2, 0.01);
	
	exponencial->execute(0, 100, 1);
	
	Model::StockIterator it = exponencial->systemBegin();
	for(int i = 0; it != exponencial->systemEnd(); it++, i++)
	{
		assert(((*it)->getValue() - expected[i]) <= 0.001);
	}

	cout << "Model Exponencial - OK" << endl;
}

void ModelLogistico()
{
	double expected[2] = {352.595, 21.7833};

	Model* logistical = Model::createModel("logistical");

	System* p1 = logistical->createSystem("p1", 100, 70);
	System* p2 = logistical->createSystem("p2", 0, 70);

	logistical->createFlow<Logistico>("logistical", p1, p2, 0.01);
	
	logistical->execute(0, 100, 1);

	Model::StockIterator it = logistical->systemBegin();
	for(int i = 0; it != logistical->systemEnd(); it++, i++)
	{
		assert(((*it)->getValue() - expected[i]) <= 0.001);
	}

	cout << "Model Logistico - OK" << endl;
}

void testesStock()
{
    System& s1 = (*new SystemHandle("System1", 100.0, 100.0));
    System& s2 = (*new SystemHandle("System2", 10.0, 100.0));

	assert(s1.getValue() == 100.0);
	assert(s1.getMaxValue() == 100.0);

	s1.setID("System1");
	assert(s1.getID() == "System1");

	assert(s1+s2 == 110.0);
	assert(5.5+s2 == 15.5);
	assert(s1+5.5 == 105.5);

	assert(s1-s2 == 90.0);
	assert(fabs(5.5-s2) == 4.5);
	assert(s1-5.5 == 94.5);

	assert(s1*s2 == 1000.0);
	assert(5.5*s2 == 55.0);
	assert(s1*5.5 == 550.0);

	assert(s1/s2 == 10.0);
	//assert(5.5/s2 == 0.55);
	assert(fabs(s1/5.5 - 18.181818) <= 0.001);

	s1.setValue(1.2);
	assert(s1.getValue()==1.2);

	s1 = s2;
	assert(s1.getMaxValue() == s2.getMaxValue());

	cout << "System Unitario - OK" << endl;
}

void testesFlow()
{
	System& s1 = (*new SystemHandle("System1", 100, 70));
    System& s2 = (*new SystemHandle("System2", 0, 70));
	Exponencial* f1 = new Exponencial("Flow", &s1, &s2, 0.01);
	Exponencial* f2 = new Exponencial("Flow2", new SystemHandle("System22", 25, 70), new SystemHandle("System23", 18, 70), 0.01);

	f1->setID("Flow1");
	assert(f1->getID()=="Flow1");

	f1->setSource(&s1);
	assert(f1->getSource()==&s1);

	f1->setTarget(&s2);
	assert(f1->getTarget()==&s2);

	//assert(f1->execute() == 1);

	f1 = f2;
	assert(f1->getID() == f2->getID());
	assert(f1->getSource() == f2->getSource());
	assert(f1->getTarget() == f2->getTarget());

	cout << "Flow Unitario - OK" << endl;

    delete f1;
}

void testesModelo()
{
    Model* m1 = Model::createModel("Model");
    System* s1 = m1->createSystem("System1",100, 70);
    System* s2 = m1->createSystem("System2",0, 70);
	m1->createFlow<Exponencial>("Flow1", s1, s2, 0.01);

	Model* m2 = Model::createModel("Model2");
	System* s3 = m2->createSystem("System3",100, 70);
    System* s4 = m2->createSystem("System4",10, 70);
	m2->createFlow<Logistico>("Flow2", s3, s4, 0.01);

	m1->setID("Model1");
	assert(m1->getID()=="Model1");

	m1->execute(0, 100, 1);
	assert(fabs(s1->getValue() - 36.6032) <= 0.001);
	assert((s2->getValue() - 63.3968) <= 0.001);

	m2->execute(0, 100, 1);
	m1 = m2;
	assert(m1->getID() == m2->getID());
    assert((*m1->systemBegin())->getValue()  - (*m2->systemBegin())->getValue() <= 0.001);
	assert((*m1->systemBegin()++)->getValue() - (*m2->systemBegin()++)->getValue() <= 0.001);

	cout << "Model Unitario - OK" << endl;
}

int main()
{
	testesStock();
	testesFlow();
	testesModelo();
    cout << "\tTestes Unitarios - OK" << endl;
    cout << endl;

	ModelExponencial();
	ModelLogistico();
    cout << "\tTestes Funcionais - OK" <<endl;
    cout << endl;

	return 0;
}