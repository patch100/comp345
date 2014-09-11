Hello,

SDL is already included in the package. The C++ files are in /include/, and the .dll files are in the same folder as Main.cpp (comp345/TDgame/TDgame)

All you have to do is open the project, right click on the project in the right side tool bar. Go to Properties->Linkers->General->Additional Library Directives.

Then add the folder that contains all the files (comp345/TDgame/TDgame).

Then, go to Properties->Linkers->Input-> Additional Dependencies-> Edit, and add : "SDL2.lib;SDL2main.lib;"

All the sdl cpp files are included, so just go to (comp345/TDgame/TDgame/include) if you want to add them.

Then running the code will get you the application window.

Good Luck!


