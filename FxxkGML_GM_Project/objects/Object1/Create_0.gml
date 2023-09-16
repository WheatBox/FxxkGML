FxxkGML_Init("game.dll");

var fgmver = FxxkGML_GetVersion();
if(FGM_VERSION_LEFT != fgmver.left || FGM_VERSION_MID != fgmver.mid || FGM_VERSION_RIGHT != fgmver.right) {
	show_debug_message($"WARNING! FGM version of game.dll is {fgmver.left}.{fgmver.mid}.{fgmver.right}!");
	show_debug_message($"But the game's is {FGM_VERSION_LEFT}.{FGM_VERSION_MID}.{FGM_VERSION_RIGHT}!");
} else {
	show_debug_message($"FGM version: {FGM_VERSION_LEFT}.{FGM_VERSION_MID}.{FGM_VERSION_RIGHT}");
}
