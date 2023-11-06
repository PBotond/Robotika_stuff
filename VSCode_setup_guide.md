# Visual Studio Code telepítése és beállítása Arduino programozásához

##### A VSCode egy nyílt forráskódú fejlesztői környezet, amelyet a Microsoft fejleszt. Bővítményei lehetővé teszik, hogy egyetlen környezetben akár különböző nyelveken kódoljunk, továbbá olyan eszközöket tartalmaz - mint a függvények definícióinak megtekintése, a verziókezelés, vagy az intelligens kódkiegészítés - melyek az Arduino IDE-ben nem találhatóak meg.

 1. **VSCode telepítése:** Telepítsd a VSCode-ot! [Innen tudod letölteni.](https://code.visualstudio.com/)
	 > :warning: **Figyelem!** Az infotermi gépeken csak a hordozható, azaz telepítő nélküli verzió fog működni, diákként nincs telepítési jogod... Ehhez a letöltéskor a [.zip opciót](https://code.visualstudio.com/sha/download?build=stable&os=win32-x64-archive) válaszd, majd egyszerűen csomagold ki, például az asztalra!
 2. **Kiterjesztés telepítése:** Nyisd meg a bővítmények panelt a bal oldali menüoszlopból a "négy doboz" ikonra kattintva, vagy a <kbd>Ctrl</kbd>+<kbd>Shift</kbd>+<kbd>X</kbd> billentyűkombinációtval, majd a keress rá az "Arduino" szóra! Az első találatot ("Arduino for Visual Studio Code" leírással) telepítsd az *Install* gombbal!
	
	![A kiegészítő telepítése](https://raw.githubusercontent.com/PBotond/Robotika_stuff/master/img/vscode_setup_1.png)

 3. **Arduino csatlakoztatása:** Ha eddig nem tetted volna, csatlakoztasd az Arduino kártyát a számítógép USB-portjához!
 4. **Munkakörnyezet beállítása:** A *File* &rarr; *Open folder* menü választásával nyisd meg azt a mappát, amibe a projektjeidet szeretnéd menteni (vagy ahová már mentetted őket korábban)!
	 > :warning: **Figyelem!** Az egyes programok `.ino` fájljait velük azonos nevű könyvtárakba kell elhelyezni, különben nem fog működni a fordítás! Erre mindig figyelj, sok bosszúságot meg lehet vele spórolni. :wink:
 5. **Arduino program kiválasztása:** A VSCode Arduino kiegészítőjéhez csomagolva letöltődik az Arduno CLI (Command Line Interface, Parancssoros felület) program is, melyre szükség van a fordításhoz és feltöltéshez, azonban ennek használatát először be kell állítani. Ezt a *Settings* (<kbd>Ctrl</kbd>+<kbd>,</kbd>) &rarr; *Arduino: User Arduino CLI* opció bepipálásával teheted meg.

	![Az Arduino CLI használatának beállítása](https://raw.githubusercontent.com/PBotond/Robotika_stuff/master/img/vscode_setup_2.png)
 6. **Fordítás és feltöltés:** 
	-  Nyiss meg egy `.ino` fájlt! (Például valamelyiket ebből a
    repóból...) Kattints az alsó menüszalagban *\<Select Board Type>*
    gombra, majd a megjelenő panelen válaszd az *Install a board with
    the Boards Manager* lehetőséget, a következő ablakban pedig
    telepítsd (*Install*) az *Arduino AVR Boards* nevű csomagot! (Ha
    Arduino Uno helyett más fajta kártyát használsz, válaszd az annak
    megfelelő opciót!)
      
	    ![A Board Manager csomag letöltése](https://raw.githubusercontent.com/PBotond/Robotika_stuff/master/img/vscode_setup_3.png)
    - Ha befejeződött a telepítés, nyisd meg újra a *Board Configuration* ablakot a *\<Select Board Type>*-ra kattintva, a legördülő menüből pedig válaszd ki az Arduino kártyád típusát!
    -  Kattints az alsó menüszalagban a *\<Select Programmer>* gombra, és
    válaszd az *AVR ISP* lehetőséget! (Ha nincs ilyen, válassz egy másikat a listából!)
    - A soros interfész beállításához, amelyen a Visual Studio Code kommunikálni fog az
    Arduino Unóval, kattints az alsó menüszalagban a *\<Select Serial Port>* gombra! Ezután válaszd ki a megnyíló listából a megfelelő portot!
    - Ha nem állítódna be automatikusan, a *\<Select Sketch>* gombra kattintva válaszd ki a fordítani kívánt forrásfájlt!
    - Ellenőrzéshez és feltöltéshez a program jobb felső sarkában található ikonokat használhatod.
    
	    ![A beállított program](https://raw.githubusercontent.com/PBotond/Robotika_stuff/master/img/vscode_setup_4.png)
