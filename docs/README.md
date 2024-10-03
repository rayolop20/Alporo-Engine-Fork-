# AlporoEngine Fork -The Seed Engine- 
AlporoEngine is A finished Videogame Engine, Created by Alex Garcia Selma and Pol Maresch Marxuach, this engine is created for a UPC CITM university suject VideoGame Engine. Curse 2022-2023.

***

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

![Pol](https://user-images.githubusercontent.com/79161063/212733053-13a7e5bc-07f6-49ad-890c-4e590d49e71c.PNG)

I am a video game programmer and designer studying at the CITM, UPC. I've been a fan of videogames all my life and now I have to create them.

My contribution(In the Sub-System):

- Created UI Canva, UI Button, UI Background
- Maked The Ui Design In Game
- Created UI System

***

# Main Features

## Camera Controls
- Default Mode:
  * Mouse wheel scroll = Zoom in and out.
  * Mouse wheel click = move around.
  * 'F' = focus camera to selected object.
- In game
  * 'F1': Activate UI Opcions
  * Mouse: Interact With Game Scene
  
* Right Mouse Key:

-Mouse Movement: Camera Direction 

-W Keys: Front Camera movement.

-A Keys: Left Camera movement.

-S Keys: Right Camera movement.

-D Keys: Back Camera movement.

-Q Keys: Move Camera Up.

-E Keys: Move Camera Down.

- Focused Mode ('Alt' + mouse left click pressed):
  * Mouse movement = orbit selected object
  
***

## Main Screen
In this screen you can edit what you will see In-Game you can add:

*GameObjects*: This are the main edditable and costumizable part of the engine, you can transform, rotate, scale, put and change textures the way you want, you can put childs on them and will sacale rotate and transform like his parent.

*Ui Objects*: This ones works like game objects put they will be in orthografic view In-Game and you could interact with them while you play.

### Header menu
* Play/Stop button: start/stop gameplay delta time.
* Pause/Unpause button: pause delta time.
* Speed button: toggle between increased game velocity (x1, x2, x4).

### Inspector
When you choose a GameObject in will show the features of that GameObject, the main features are:

* Transform
* Mesh
* Texture
* Camera

### Game
The main cameera where you can test what the player will see, the mainfeatures are:

* Only rendering necessary game objects.
* Draws from scene main camera (Frustum culling activated).
* It will also show the Ui Objects in orthographic mode. 

### Assets
Here  you can see all the assets and all the files you can use to make the game, the main features are:

* Tracks project Assets folder files.
* Navegate through folders (double left click to enter folders, top buttons to backup).
* Create folders.
* Move to: move file/folder through folders.
* Rename: rename files & folders (file extensions will be preserved).
* Delete: delete file/folder.


***

## Additional features
    
 * Drag and drop:
   - If you drop any FBX or DAE on the scene the game object will be created with child objects that store their meshes, if the FBX has a texture, and is loaded in Assets folder, it will be loaded automatically.
   -  If you drop any PNG, DDS or TGA image can be dropped on the scene. This will be loaded as the selected game object texture (creating a Texture Component if there isn't one yet).


***

## UI Sub-System

### Features:

You can create buttons in the scene that will show in orthogaphic mode in the game camera,
there you can moddify them the way you want.

- UI Butons Added (you can create on ImGui Interface)
	* Butons Type:
	- Canva
	- Button
	- CheckBox
	- Background
- In Game:
	- You can Drag and drop the Background (Activate on inspector)
	- You Press Play and Fade out The Background
### Fade Out
![ezgif com-gif-maker](https://user-images.githubusercontent.com/79161063/212733612-21d56322-b7cd-4765-acec-c74924497f8f.gif)

### F1:
- If F1 is presed, you can see UI options
  
![F1](https://user-images.githubusercontent.com/79161063/212734264-205ea946-cfd1-493e-aff8-38324e8e88be.gif)

### Vsync:
- With  UI options Avaliable you can press on Checkbox and Activate and Desactivate Vsync
  
![Vsinc](https://user-images.githubusercontent.com/79161063/212734302-ab054b22-275c-4c4b-bf1d-a4fb90e94ada.gif)

- In game Keys
  * 'F1': Activate UI Opcions
  * Mouse: Interact With Game Scene

***
## Link to the last version of the game engine

Github adress: [Last Release](https://github.com/rayolop20/Alporo-Engine-Fork-/releases/tag/v.3)

## Video Example

[Video Link](https://youtu.be/tslw53VUlfQ)

## Creators 
### Github

[Pol Maresch](https://github.com/rayolop20)

[Alex Garcia](https://github.com/MaralGS)

## Fork Creators

- Biel Rabasa
    * Github Account: [bielrabasa](https://github.com/bielrabasa)


- Roger Salas
    * Github Account: [Draquian](https://github.com/Draquian)
