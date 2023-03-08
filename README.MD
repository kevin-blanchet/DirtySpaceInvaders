
# Dirty Space Invaders

## Threshold 0

* Set `rGen` to `static`
* Initialized `controllerInput` in `PlayField` constructor (also set `iBounds` as const ref)
* Fixing a bug where the process tries to access, add and delete game objects in the same iteration:
	* Adding two game object vector, `awaitingDeletion` and `awaitAddition`, to store game objects to be deleted and added at the end of the update cycle
	* Adding new functions `DeleteObject` and `CreateObject`
	* Moved all code from `RemoveObject` to `DeleteObject` and from `AddObject` to `CreateObject`. `RemoveObject` and `AddObject` now simply add the reference of the object to remove or add respectively to the `awaitingDeletion` and `awaitAddition` vectors.
	* Added new loops in `Update` to delete and add all game objects awaiting deletion and addition respectively
	* Removed `delete` call from `PlayerLaser`'s update
* Corrected a spelling error for `PlayerShip` in `GetPlayerObject`
* Corrected a spelling error for `AlienLaser` in `PlayField::SpawnLaser()`
* Added `nullptr` checks around every `GetPlayerObject` call
* Removed `delete` call from `DeleteObject`
* Moved the `new` call from children of `GameObject` to `GameObject()`
* Fixed Aliens initial y position
* Fixing a bug where player lasers are not colliding with aliens
	* Created a Laser parent class
	* Set the `CollisionCheck` function for the player lasers to remove aliens

## Threshold 1

* Moved classes in header files
* Moved function definitions in source files
* Moved the `delete[]` call from children of `GameObject` to `virtual ~GameObject()`
* Initialized `rGen` seed
* Used pointers instead of references in ships updates
