#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Engine.h"
#include <list>
#include <memory>
#include <functional>
#include <optional>
#include <thread>
#include <future>

using engine_ptr = std::shared_ptr<Engine>; //engine
using container = std::list<engine_ptr>; //data
using Predicate = std::function<bool (const engine_ptr&)>;
using ThreadContainer = std::list<std::thread>;

//using engine_list = std::list<Engine*>;

void CreateObjects(container&); //an empty container reference

//input container reference, function wrapper for predicate o/p--> container of matching instance
std::optional< container> ReturnMatchingInstance(const container& engines, const Predicate& fn);

//input container reference, function wrapper for predicate o/p--> bool 
bool AtleastOneMatchingInstance(const container& engines, const Predicate& fn);


float AverageCCValue(container&);

void CreateThreads(ThreadContainer&);

#endif // FUNCTIONALITIES_H
