# RAMDE
## Assignment 2 - Moore and Mealy State Machines - Light Switch

## Objectives:
The objective of this assignment is to use MPS to develop a Domain Specific Language (DSL) for two state machines: a Moore state machine and a Mealy state machine.

By doing that, we explore several aspects of DSL creation: model validation, syntax customization, model queries, code generation, etc.

## Theoretical Concepts
### DSL
Domain Specific Language (DLS) is a programming language with a higher level of abstraction specialized to a particular application or use cases which uses the concepts and rules from the field or domain.

Making it more efficient to design an application and to find and correct errors of logic. Also allows a smoother development of the application since it's possible for non-developers and people who do not know the domain understand the overall design.

Some examples of DSL are: CSS, make and SQL

### State Machine
A State Machine or a Finite State Machine (FSM) is a model that describes the behavior of the system it represents. This model consists in a finite number of states (one of which is the starting state), inputs and transitions.

For each input received on the machine, it has a corresponding transition from the current state to another state.

There are two basic types of state machines: Moore state machines and Mealy state machines. The two types can always be translated into each other.

### Moore State Machine
A Moore state machine is a state machine that produces outputs only on states.

### Mealy State Machine
A Mealy state machine is a state machine that produces outputs only on transitions.

## Solution Design
### Description
These two solutions consist of a DSL and respective generated java code for a Moore state machine and another for Mealy state machine, built in MPS, that abstracts a light switch.

The DSLs created may be classified as a Vertical, Imperative, Textual, Internal and code-generating DSLs.

The light switch has:

- Three different brightness levels: Dimmed, Meddium and High.
- Two buttons: On and Off.

The button On cycles through the different brightness levels ( Dimmed >> Medium >> High >> Dimmed >> etc.) and turns the light Dimmed when the light is off.

When a button is pressed, an event is raised and the machine changes state and can generate outputs accordingly.


## Solution Implementation
First, we created a Solution project and added a new language to it for each state machine. Under Language/structure we created the following Concepts for both projects:

|	**Concept**		|	**Children**		|	**References**	|	**implements**	|	**Root**	|	**Used in**				|
|	:----------:	|	:----------:		|	:------------:	|	:------------:	|	:------:	|	:------------------:	|
|	action			|						|					|	INameConcept	|	false		|	Moore and Mealy			|
|	event			|						|					|	INameConcept	|	false		|	Moore and Mealy			|
|	state			|	transition[0..n]	|	action[0..1]	|	INameConcept	|	false		|	Moore					|
|	state			|	transition[0..n]	|					|	INameConcept	|	false		|	Mealy					|
|	StateMachine	|	event[0..n]			|	initialState[1]	|	INameConcept	|	true		|	Moore and Mealy			|
|					|	action[0..n]		|					|	IMainClass		|				|							|
|					|	state[0..n]			|					|					|				|							|
|	transition		|						|	event[0..1]		|	INameConcept	|	false		|	Moore					|
|					|						|	target[0..1]	|					|				|							|
|	transition		|						|	event[0..1]		|	INameConcept	|	false		|	Mealy					|
|					|						|	target[0..1]	|					|				|							|
|					|						|	action[0..1]	|					|				|							|


Then, we created three new j.mmps.baseLanguage classes in the generator:

- Main
- AStateMachine
- DisplayStateMachine

The Main class is the entry point of the solution and it's used for testing. This class has only pure java code.

The class AStateMachine is the implementation of the state machines, combining java code with property MACROS which will replace the parts of the code affectedd by the MACRO with the values definned on the state machine models instances.

The class DisplayMachine was created for demonstration reasons and has only a print method.

After defining the language, we proceded to create a new StateMachine from the solution sandbox named "LightSwitch". In the Light Switch we created the states, transitions and actions defined inn the language structure.

At this point we rebuild the language and the model to update them and check the generated java code for errors. This step was repeted until no errors were found.

### Tests an Analyses
We tested the DSL by executing the java code generated in MPS.

The Main class of the generator creates a new instance of the state machine and executes it, simulating the events and printing the current state to the console, calling the methods defined on the class AStateMachine:

![image](./LightSwitch-Console.png)

## Further Considerations

- The following upgrades could be implemented in both projects:

      - To facilitate future changes in the DSL, because MPS uses polymorphism:
 
          * Remove the child collection of the type "State" in the Concept "StateMachine".
          * Create an Interface Concept "IStateMachineContent" and add it as a child collection in the Concept "StateMachine".
          * Concept "State" implements "IStateMachineContent".
          * Add a child collection of the type "IStateMachineContent" to the "StateMachine" Concept.
   
      - To facilitate future changes in the lDSL, because Transitions can be triggered by other things than events in the future:
 
          * Remove the reference of the type "Event" in the Concept "Transition".
          * Create an Abstract Concept "Trigger" and add it as a child collection in the "Transition" Concept.
          * Create an Concept "EventTrigger" that extends the Concept "Trigger" and refereces an "Event".
          * Create an alias for the Concept "Transition".
   
      - To prevent errors by addding constraints in the DSL:
 
          * Add Typesystem checking rules (e.g. duplicate states, Namming Case, number of initial states).	
   
      - To prevent errors by addding constraints in the DSL:
 
          * Change the scoop of the Reference "target" in the Concept "Transition" in the Concept constraints.
          * Change the scoop of the Reference "event" in the Concept "EventTrigger" in the Concept constraints.
___

## References
* [Itemis - State Machines](https://www.itemis.com/en/yakindu/state-machine/documentation/user-guide/overview_what_are_state_machines?hsLang=de)
* [MPS - DSL](https://www.jetbrains.com/mps/concepts/domain-specific-languages/)
