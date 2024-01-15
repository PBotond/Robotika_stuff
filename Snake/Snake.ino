/**** INCLUDE-OK ****/
#include <LedControl.h> //Programkonyvtar hozzaadasa a kijelzo kezelesehez

/**** KIJELZO BEALLITAS ****/
constexpr auto DIN = 11, CLK = 13, CS = 10;  // A MAX7219 LED-vezerlohoz csatlakozo pinek
LedControl lc = LedControl(DIN, CLK, CS, 0); // Objektum peldanyositasa

/**** STRUKTURAK ****/
struct snake
{
  int x;
  int y;
  bool gyumolcs;
};
typedef struct snake snake; // Snake struktura a kigyo elemeinek (koordinatainak) tarolasara

/**** KONSTANSOK ****/
const int maxKigyoHossz = 64, kigyoSebesseg = 200;

/**** GLOBALIS VALTOZOK ****/
char haladasiIrany = 'w';   // A kigyo aktualis haladasi iranya
snake kigyo[maxKigyoHossz]; // A kigyo teste
snake gyumolcs;             // Az aktualisan megszerezheto gyumolcs
int kigyoHossza = 3;        // A kigyo aktualis hosszusaga

/**** SAJAT FUGGVENYEK ****/
bool Ellenorzes(snake keresett) // Eldonti, hogy egy adott koordinata-par eleme-e a kigyonak
{
  for (int i = 0; i < kigyoHossza + 1; i++)
  {
    if (kigyo[i].x == keresett.x && kigyo[i].y == keresett.y)
    {
      return true;
    }
  }
  return false;
}

snake RandomKoordinata() // Visszaad egy koordinata-part, ami biztosan nem eleme a kigyonak
{
  snake randomKoord;
  randomKoord.gyumolcs = true;
  while (1)
  {
    randomKoord.x = random(0, 8);
    randomKoord.y = random(0, 8);

    if (!Ellenorzes(randomKoord))
    {
      return (randomKoord);
    }
  }
}

/**** THE_END FUGGVENY ****/
/*
A fuggveny feladatai:
(1. meno vege.)
2. vegtelen ciklus.
*/
void THE_END()
{
  Serial.println("Vesztettél!!!");

  while (1)
  {
    for (int i = 0; i <= 10; i++)
    { // időzítés

      for (int i = 0; i <= 7; i++)
      {

        for (int j = 0; j <= 7; j++)
        {
          lc.setLed(0, i, j, true);
        }

        for (int i = 0; i <= 7; i++)
        {

          for (int j = 0; j <= 7; j++)
          {
            lc.setLed(0, i, j, false);
          }
          delay(20);
        }
      }
    }
    Serial.println("Hogy lehetsz ilyen béna???");
    Serial.println("Béna!!");
    Serial.println("Én megprogramoztam, te meg arra sem vagy képes hogy játsz vele???");
    Serial.println("Szégyeld magad!!!");
  }
}

/**** SETUP FUGGVENY ****/
/*
A fuggveny feladatai:
  1. LED-vezerlo inicializalasa
  2. Kigyo kezdeti elhelyezese
  3. Soros kommunikacio es random seed beallitasa
  4. Gyumolcs kezdeti elhelyezese (TODO0)
*/
void setup()
{
  /* Kijelzo inicializalas */
  lc.shutdown(0, false); // Energia-takarekos mod kikapcsolasa
  lc.setIntensity(0, 0); // LED-ek fenyerossegenek beallitasa
  lc.clearDisplay(0);    // Kijelzo torlese (ha lenne rajta valami szemet)

  /* Kigyo kezdeti helyenek kirajzolasa */
  for (int i = kigyoHossza - 1; i >= 0; i--)
  {
    kigyo[i].x = 4;                   // Vizszintesen kozepen
    kigyo[i].y = kigyoHossza - 1 - i; // Fuggolegesen kozeprol indulva
    kigyo[i].gyumolcs = false;
    lc.setLed(0, kigyo[i].x, kigyo[i].y, true); // A kigyo egyes pontjaihoz tartozo LED-ek bekapcsolasa
    delay(kigyoSebesseg);                       // Kesleltetes
  }

  Serial.begin(115200); // Soros kommunikacio inditasa a vezerlo szamitogeppel

  randomSeed(analogRead(0)); // Seed a random szamok generalasahoz (EM-zaj egy analog bemenetrol)

  gyumolcs = RandomKoordinata();
  lc.setLed(0, gyumolcs.x, gyumolcs.y, true); // Kigyo fejenek megfelelo LED felkapcsolasa
}

/**** LOOP FUGGVENY ****/
/*
A fuggveny feladatai:
  1. Input olvasasa a soros portrol, ennek megfeleloen a kovetkezo haladasi irany meghatarozasa (vagyis: kanyarodas)
  2. Kigyo farkanak eltavolitasa, vagy megnovesztese (TODO1)
  3. Kigyo testenek leptetese elore (TODO1)
  4. Kigyo fejenek elhelyezese a kovetkezo helyere (esetleges atlepes a kepernyo hataran)
  5. Utkozes-vizsgalat (Gyilkolo)
  6. Gyumolcs-megeves-vizsgalat, uj gyumolcs elhelyezese (TODO3)
*/
void loop()
{
  /* Kovetkezo haladasi irany meghatarozasa*/
  if (Serial.available()) // Az irany csak akkor valtozzon, ha van fel nem dolgozott karakter a soros port buffereben
  {
    if (haladasiIrany == 'w') // Jelenleg felfele halad a kigyo, jobbra es balra kanyarodhat
    {
      switch (Serial.read())
      {
      case 'a':
        haladasiIrany = 'a';
        break;

      case 'd':
        haladasiIrany = 'd';
        break;

      default:
        break;
      }
    }

    if (haladasiIrany == 'a') // Jelenleg balra halad a kigyo, felfele es lefele kanyarodhat
    {
      switch (Serial.read())
      {
      case 'w':
        haladasiIrany = 'w';
        break;

      case 's':
        haladasiIrany = 's';
        break;

      default:
        break;
      }
    }

    if (haladasiIrany == 's') // Jelenleg lefele halad a kigyo, balra es jobbra kanyarodhat
    {
      switch (Serial.read())
      {
      case 'a':
        haladasiIrany = 'a';
        break;

      case 'd':
        haladasiIrany = 'd';
        break;

      default:
        break;
      }
    }

    if (haladasiIrany == 'd') // Jelenleg jobbra halad a kigyo, felfele es lefele kanyarodhat
    {
      switch (Serial.read())
      {
      case 'w':
        haladasiIrany = 'w';
        break;

      case 's':
        haladasiIrany = 's';
        break;

      default:
        break;
      }
    }
  }

  if (kigyo[kigyoHossza - 1].gyumolcs == true)
  {
    kigyo[kigyoHossza - 1].gyumolcs == false;
    kigyoHossza++;
  }
  else
  {
    // TODO1
    lc.setLed(0, kigyo[kigyoHossza - 1].x, kigyo[kigyoHossza - 1].y, false); // A kigyo farkanak lekapcsolasa
  }

  for (size_t i = kigyoHossza - 1; i > 0; i--) // A kigyo elemeinek leptetese
  {
    // TODO1
    kigyo[i] = kigyo[i - 1];
  }

  snake kovetkezoFej = kigyo[0];
  /* Kigyo fejenek elkanyaritasa a megfelelo iranyba */
  switch (haladasiIrany)
  {
  case 'w':
    kovetkezoFej.y++;
    break;

  case 'a':
    kovetkezoFej.x--;
    break;

  case 's':
    kovetkezoFej.y--;
    break;

  case 'd':
    kovetkezoFej.x++;
    break;

  default:
    break;
  }

  /* A kepernyo hataran valo atlepes */
  if (kovetkezoFej.y > 7)
  {
    kovetkezoFej.y = 0;
  }
  if (kovetkezoFej.x > 7)
  {
    kovetkezoFej.x = 0;
  }
  if (kovetkezoFej.y < 0)
  {
    kovetkezoFej.y = 7;
  }
  if (kovetkezoFej.x < 0)
  {
    kovetkezoFej.x = 7;
  }


  /**** Gyilkolo ****/
  /*
A  feladatai:
1. Utkozes erzekelese
2. jatek vege.
*/
  if (Ellenorzes(kovetkezoFej))
  {
    THE_END();
  }
  else
  {
    kigyo[0] = kovetkezoFej;
  }


  if (kigyo[0].x == gyumolcs.x && kigyo[0].y == gyumolcs.y)
  {
    kigyo[0].gyumolcs = true;
    gyumolcs = RandomKoordinata();
    lc.setLed(0, gyumolcs.x, gyumolcs.y, true);
  }

  
  lc.setLed(0, kigyo[0].x, kigyo[0].y, true); // Kigyo fejenek megfelelo LED felkapcsolasa

  delay(kigyoSebesseg); // Kesleltetes
}