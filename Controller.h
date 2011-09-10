#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include <map>

namespace evolver {

  class Actor;
  
  enum ActorAction { UP, DOWN, LEFT, RIGHT, NOT_AN_ACTION };

  class Controller {
  public:
    Controller (void);
    ~Controller (void);
    Controller (const Controller &original);

    Controller &operator= (const Controller &original);

    Actor *getControlled (void);
    enum ActorAction controlToAction (int control);

    void setControlActionPair (int control, enum ActorAction action);
    void setControlled (Actor *controlled);

    void handleControl (enum ActorAction, float timeElapsed);

  protected:
    void copyController (const Controller &original);

  private:
    std::map<int, enum ActorAction> *controls;
    Actor *controlled;

  };

}

#endif
