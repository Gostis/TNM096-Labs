% Author: Jacob Nyman
% Date: 2019-05-10

% TASK A

%actions
act(go(X,Y),                                          % action name
  [shakey(L), in(L, X), on(L, floor), connect(X,Y)],  % preconditions
  [in(L,X)],                                          % delete
  [in(L,Y)]                                           % add
).

act( push(B, X, Y),
     [shakey(L), b(B), on(L,floor), in(L,X), in(B,X), connect(X,Y)],
     [in(L,X), in(B,X)],
     [in(L,Y), in(B,Y)]
).

act( climbUp(B),
     [shakey(L), b(B), on(L,floor), in(L,X), in(B,X)],
     [on(L, floor)],
     [on(L, B)]
).

act( climbDown(B),
     [shakey(L), b(B), on(L,B), in(L,X), in(B,X)],
     [on(L, B)],
     [on(L, floor)]
).

act( turnOn(Switch),
     [shakey(L), light(Switch, false) , on(L, B), in(L,X), in(B,X)],
     [light(Switch, false)],
     [light(Switch, true)]
).

act( turnOff(Switch),
     [shakey(L), light(Switch, true) , on(L, B), in(L,X), in(B,X)],
     [light(Switch, true)],
     [light(Switch, false)]
).
     
%goal_state( [in(l,room1)] ).
%goal_state( [light(switch1, false)]).
goal_state( [in(b2, room2)]).
 %goal_state([in(l,room1),light(switch1, false),in(b2, room2)]).

initial_state([
               %Shakey
               
               shakey(l),
               in(l,room3),
               on(l,floor),
               
               %Boxes
               b(b1),
               b(b2),
               b(b3),
               b(b4),

               %Rooms
               room(room1),
               room(room2),
               room(room3),
               room(room4),
               room(corridor),
               
               %B locations
               in(b1, room1),
               in(b2, room1),
               in(b3, room1),
               in(b4, room1),
               
               % Lights
               light(switch1, true),
               light(switch2, false),
               light(switch3, false),
               light(switch4, true),
               
               %Connect lights to Rooms
               connect(switch1, room1),
               connect(switch2, room2),
               connect(switch3, room3),
               connect(switch4, room4),
               
               connect(room1, switch1),
               connect(room2, switch2),
               connect(room3, switch3),
               connect(room4, switch4),
               
               %Connect rooms to Corridor
               connect(corridor, room1),
               connect(corridor, room2),
               connect(corridor, room3),
               connect(corridor, room4),
               
               connect(room1, corridor),
               connect(room2, corridor),
               connect(room3, corridor),
               connect(room4, corridor)
]).