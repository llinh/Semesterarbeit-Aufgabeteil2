# Semesterarbeit-Aufgabeteil2
Aufgabenteil 2: BeschreibungZiel des Aufgabenteils ist die Programmierung und Gestaltung eines graphischen Spiels unter Verwendung von C++ und QT. 

Der Spieler / die Spielerin soll eine kleine geometrische Figur mittels der Pfeiltasten rechts entlang einer Line am unteren Ende des Spielfeldes steuern können. Von der oberen Spielfeldkante treten „Gegenstände“ ins Spiel ein, die sich zum unteren Ende des Spielfelds bewegen. Ziel des Spiels ist das Ausweichen vor den fallenden Gegenständen und dadurch das möglichst lange „Überleben“. 

Der Aufgabeteil kann in 4 Stufen erfüllt werden. Es empfiehlt sich allerdings, alle Stufen zu durchdenken und ein Konzept zu entwickeln, dass das Erfüllen aller Aufgaben berücksichtigt, bevor die eigentlichen Implementierung beginnt. 

Stufe I – Basisaufgabe1. Ein Button „Start“ bzw. „Pause“ startet bzw. stoppt das Spiel. Vorzugsweise wechselt ein Button die Beschriftung. 

2. Am unteren Rand einer Zeichenfläche (~Spielfeld) lässt sich – mit Hilfe der Pfeiltasten – ein schraffiertes Quadrat nach links/rechts steuern. Dieses repräsentiert den „Avatar“ des Spielers.

3. Ein Button „Speichern“ sichert den Zustand des Spiels und seiner Objekte in ein „Savegame“.

4. Ein Button „Laden“ lädt die Informationen aus dem „Savegame“ und stellt den zuletzt gespeicherten Zustand wieder her. 

5. Links oben zeigt eine Zahl einen Punkte-Counter an. Er steigt gleichmäßig und regelmäßig an.

6. Rechts oben zeigen drei ausgefüllte geometrische Formen (z.B. Kreise oder Herzen) die drei Leben des Spielers an.

7. Das Spiel generiert Objekte, die das Spielfeld am oberen Rand betreten und sich zum unteren Rand bewegen. Wenn Sie diesen überschreiten, werden die Objekte aus dem Spiel entfernt. (ggf. Stufe II beachten!)

Stufe IIDie Basisaufgabe wird realisiert. Zusätzlich: Das Spiel generiert zufällige, unterschiedliche Objekte, die das Spielfeld am oberen Rand betreten und sich zum unteren Rand bewegen. Die unterschiedlichen Objekte werden durch verschiedene Konfigurationen einer Klasse erzeugt. Sie unterscheiden sich in den Parametern Geschwindigkeit, Form und Farbe. Gleiches Aussehen (Form & Farbe) bedeutet gleiches Verhalten (Bewegung).

Kollidiert eines der Objekte mit dem „Avatar“ des Spielers, so verliert dieser ein Leben und das Spiel „friert“ für einen Augenblick ein. Verliert der Spieler ein Leben, so wird eine Darstellung der Spielerleben nicht mehr ausgefüllt, sondern als leerer Rahmen angezeigt. Verliert er das letzte Leben, endet das Spiel, indem es kurz „einfriert“ und schließlich neu startet. 

Stufe IIIStufe II + Zusätzlich: Wenn der Spieler Leben verloren hat, wird sein „Avatar“ abgeschwächt dargestellt. Eine neuer Typ von Objekten, der selten vorkommt und sich optisch deutlich abhebt, regeneriert bei Kollision ein Leben, anstatt es zu entfernen. Das Spiel wird trotzdem kurz eingefroren. Verliert der Spieler alle Leben werden „Game over“ und der Punktestand groß angezeigt.

Stufe IVStufe III + Zusätzlich: Eine Kategorie von Objekten, die sich von oben durch das Spielfeld bewegen „schlägt Haken“ über das Spielfeld. Ein solches Objekt bewegt sich also im Zick-Zack. Wann immer es eine bestimme Strecke zurückgeleget hat, wird der Winkel der Bewegung verändert. Diese neuen Objekte treten seltener auf.

Die Bewegungen (gerade und Zick-Zack) sind als wiederverwendbare Funktionen anzulegen.
