# AlporoEngine Fork -The Seed Engine- 
AlporoEngine Fork -The Seed Engine-  is A finished Videogame Engine, Created by Alex Garcia Selma and Pol Maresch Marsuach, this engine is created for a UPC CITM university suject VideoGame Motors. Curse 2022-2023.

# About Us

## Alex Garcia Selma

![Alex](https://user-images.githubusercontent.com/79161220/212575210-e6446236-6b08-4a0b-aa7f-2b7d79640b96.jpg)

I'm a video game enthusiast, I've been playing them since I was very young.
When I had to decide what I wanted to study, it was clear to me instantly. The videogames are my passion and i wish one day can my job too.

My contribution(In the Sub-System):

- Created Orthografic View in game camera.
- Modified buffers.
- Created CheckBox and UI Structure.

## Pol Maresch Marxuach

![Pol](https://user-images.githubusercontent.com/79161063/212720143-b176aa81-e3f0-43c2-abe9-a2fe23e2f5b3.PNG)

I am a video game programmer and designer studying at the CITM, UPC. I've been a lifelong fan of video games and now it's time for me to create them.

My contribution(In the Sub-System):

- Created UI Canva, UI Button, UI Background
- Maked The Ui Design In Game
- Created UI System


![Fade Out](https://user-images.githubusercontent.com/79161063/212720277-e1ee1588-5dba-4561-9595-533187d9b950.gif)


## UI Sub-System

### Features:

- UI Butons Added (you can create on ImGuii Interface)
	* Butons Type:
	- Canva
	- Button
	- CheckBox
	- Background
- In Game:
	- You can Drag and drop the Background (Activate on inspector)
	- You Press Play and Fade out The Background

	- if F1 is presed, you can see UI options
	- With  UI options Avaliable you can press on Checkbox and Activate and Desactivate Vsync
	- 
- In game Keys
  * 'F1': Activate UI Opcions
  * Mouse: Interact With Game Scene


The Seed Engine is 
a game engine developed in C++ using the external libraries: 

&emsp; -&emsp;*[SDL2](https://www.libsdl.org/)*

&emsp; -&emsp;*[OpenGL](https://www.opengl.org/)* 

&emsp; -&emsp;*[ImGui](https://github.com/ocornut/imgui)*

&emsp; -&emsp;*[GLEW](https://glew.sourceforge.net/)*

&emsp; -&emsp;*[DevIL](https://openil.sourceforge.net/)*

&emsp; -&emsp;*[MathGeoLib](https://github.com/juj/MathGeoLib)*

&emsp; -&emsp;*[PhysFS](https://icculus.org/physfs/)*

***

## Guide to execute
 * Download the Engine
 * Unpack .zip
 * Execute .exe

***
## Camera Controls
- Default Mode:
  * Mouse wheel scroll = Zoom in and out.
  * Mouse wheel click = move around.
  * 'F' = focus camera to selected object.
- In game
  * 'F1': Activate UI Opcions
  * Mouse: Interact With Game Scene
  
- Fly Mode (mouse right click pressed):
  * Mouse movement = look around
  * 'W' = move forward
  * 'S' = move back
  * 'A' = move left
  * 'D' = move right
  * 'Q' = move up
  * 'E' = move down
  * 'LShift' = increase movement speed
  
- Focused Mode ('Alt' + mouse left click pressed):
  * Mouse movement = orbit selected object

***
## Windows
* Windows can be docked around the screen, or keep them floating.

### * Main Menu
In this part you can find multiple dropdowns: 
* *File*: you find a button to open a popUp about de engine, a button with the link to GitHub, and a button to close the engine.
* *Basic Shapes*: a list of basic game object shapes to create.
* *Windows*: you can open/close the other windows, and change the therme of the window to **"light"**, **"dark"**, **"soft dark"** and you can **"personalise"**
* *Render*: a button to render the meshes in wireframe, a button to render bounding boxes (AABB boxes, OBB boxes, Raycast ray & frustum planes) & scene camera options.

### * Header menu
* Play/Stop button: start/stop gameplay delta time.
* Pause/Unpause button: pause delta time.
* Speed button: toggle between increased game velocity (x1, x2, x4).

### * Inspector
It shows the components of the selected object, where you can change the name or disable it. 
* Transform
* Mesh
* Texture
* Camera

### * Hierarchy
* Show the list of the objects in the scene and their parents/children.
* Right click on any object to show menu.
* 'Delete' / 'Supr' to delete selected game object.
* Drag objects into another objects to reparent them.

### * Console
Don't be afraid to resize the console, the buttons risize with it.
* Print 3 types of LOG (Warning, System, Message) that can be filtered.
* Collapse button: stacks identic logs.
* Clear button: clear all stored LOGS of the console.
* File button: toggle button to see the line where the LOG is executed at.

### * Configuration
Headers with options over basic engine functionalities.
* *FPS*: Show and limitate FPS, information about frame calculation time.
* *Window*: Toggle Fullscreen, resize (or not) the windows, borderless mode, Window information.
* *Visual*: Let you activate some additional widgets of the windows: VSync, brightness, lights, dephts test, face culling, color material, textures.
* Hardware: Shows information about the hardware your PC is using.

### * Scene
* Scene objects rendering.
* Move with the scene camera (Frustum culling activated).
* Mouse pick.
* Debug lines: raycast, bounding boxes (AABB, OBB), main game camera frustum planes.

### * Game
* Only rendering necessary game objects.
* Draws from scene main camera (Frustum culling activated).

### * Assets
* Tracks project Assets folder files.
* Surf through folders (double left click to enter folders, top buttons to backup).
* Create folders.
* Drag & Drop files: they will be copied to currently open assets folder.
* Right click to open options menu: drag to scene, move to, rename, delete.
* Drag to scene: imports asset to scene.
* Move to: move file/folder through folders.
* Rename: rename files & folders (file extensions will be preserved).
* Delete: delete file/folder.
* Icons: set for folders, .png .fbx


***
## Additional features
* Mouse picking: clicking on a scene object will select it on hierarchy. If debug bounding boxes is active, the raycast line will be drawn on scene.
* Delta Time: time tracking to correctly update time-depending stats (and game delta time).

***
## How the game engine works
  * Game Objects:
    - Everything in the scene is stored in game objects, they have variable components to add to them, in order to be fully personalisable.
    - Game objects can be selected from the hierarchy window, this also makes the inspector appear.
    - Game objects have parents and childs, which makes them interactuate in different ways.
    - In the inspector, all of the selected game object components can be modified.
    - Disabling game objects in inspector prevents rendering itself plus all of its childs.
    
  * Components:
    - Transform: stores the information of the local position, rotation and scale. Global position is calculed by their parent transform.
    - Mesh: stores the meshes that are rendering every frame.
    - Texture: stores the texture rendering on the component mesh meshes, can be changed to print no texture, or to print default checkers texture.
    - Camera: stores the information of a camera Frustum, can be set to main camera in inspector to render in the Game window.
    
 * Drag to scene:
   - Any FBX or DAE can be dropped on the scene. A game object will be created with child objects that store their meshes, if the FBX has a texture, and is loaded in Assets folder, it will be loaded automatically.
   - Any PNG, DDS or TGA image can be dropped on the scene. This will be loaded as the selected game object texture (creating a Texture Component if there isn't one yet).

 * Demo scene:
   - A demo scene is loaded from the start.
   - A camera is created and set to main camera (it has a predefined script to test Play/Stop/Pause/Speed buttons).

***

### Third Release (UI Sistem)
##Features :

-UI Butons Added (you can create on ImGuii Interface)
	*Butons Type:
	- Canva
	- Button
	- CheckBox
	- Background
-In Game:
	- You can Drag and drop the Background (Activate on inspector)
	- You Press Play and Fade out The Background

	- if F1 is presed, you can see UI options
	- With  UI options Avaliable you can press on Checkbox and Activate and Desactivate Vsync
- In game Keys
  * 'F1': Activate UI Opcions
  * Mouse: Interact With Game Scene


Github adress: https://github.com/rayolop20/Alporo-Engine-Fork-
## Creators 

-Pol Maresch: https://github.com/rayolop20.

-Alex Garcia: https://github.com/MaralGS.

## Fork Creators

- Biel Rabasa
    * Github Account: [bielrabasa](https://github.com/bielrabasa)


- Roger Salas
    * Github Account: [Draquian](https://github.com/Draquian)
