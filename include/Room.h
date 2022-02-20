#ifndef ROOM_H
#define ROOM_H

#include "Common.h"

class Room
{
    public:
        Room() {}
        Room(const std::string& description,
             const VecStr& choices,
             const VecStr& choiceStrings,
             const VecStr& nextRoom
             ) 
            : description(description),
              choices(choices),
              choiceStrings(choiceStrings),
              nextRooms(nextRoom)
        {}
        ~Room() {}

        std::string getDescription() const
        {
            return this->description;
        }

        VecStr getNextRooms() const
        {
            return this->nextRooms;
        }

        VecStr getChoices() const
        {
            return this->choices;
        }

        VecStr getChoiceStrings() const
        {
            return this->choiceStrings;
        }

    private:
        std::string description;
        VecStr choices;
        VecStr choiceStrings;
        VecStr nextRooms;

};

#endif
