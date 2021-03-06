/*Making music with Buzzer 

  note 	frequency
  c     262 Hz
  d     294 Hz
  e     330 Hz
  f     349 Hz
  g     392 Hz
  a     440 Hz
  b     494 Hz
  C     523 Hz
*/


/*cdefgabC Cbagfedc
  111111112111111112*/
/*int songLength = 18;
char notes[] = "cdefgabC Cbagfedc ";
int beats[] = {1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,2};*/


/*Jingle Bell
eee eee egdef fff eee ddd edg eee eee egdef fff eee eggfdc  
112 112 111122112 112 112 1122112 112 111122112 112 1111124*/

int songLength = (3*10 + 5 + 5 + 6 + 4);
char notes[] = "eeeeeeegdef fffeeedddedg eeeeeeegdef fffeeeeggfdc ";
int beats[] = {1,1,2,1,1,2,1,1,1,1,2,2,1,1,2,1,1,2,1,1,2,1,1,2,2,1,1,2,1,1,2,1,1,1,1,2,2,1,1,2,1,1,2,1,1,1,1,1,2,4};

/*Happy Birthday
ccdcfe ccdcgf ccCa feed CCafag ccdcfe ccdcgf ccCa feed CCafgf
11212211121221112211122111211211121221112122111221112211121121

int songLength = (2*(6 + 6 + 4 + 4 + 6 + 5));
char notes[] = "ccdcfe ccdcgf ccCa feed CCafag ccdcfe ccdcgf ccCa feed CCafgf";
int beats[] = {1,1,2,1,2,2,1,1,1,2,1,2,2,1,1,1,2,2,1,1,1,2,2,1,1,1,2,1,1,2,1,1,1,2,1,2,2,1,1,1,2,1,2,2,1,1,1,2,2,1,1,1,2,2,1,1,1,2,1,1,2,1};
*/

int buzzerPin = 12;
int tempo = 150; //per each rest, to make song playing faster decrease this value

void setup() 
{
  Serial.begin(57600);
  pinMode(buzzerPin, OUTPUT);
}

void loop() 
{
  int i, duration;
  
  for (i = 0; i < songLength; i++) //step through the song arrays
  {
    duration = beats[i] * tempo;  //length of note/rest in ms
    
    if (notes[i] == ' ')          //is this a rest? 
    {
      delay(duration);            //then pause for a moment
    }
    else                          //otherwise, play the note
    {
      tone(buzzerPin, frequency(notes[i]), duration);
      delay(duration);            //wait for tone to finish
    }
    delay(tempo/10);              //brief pause between notes
  }
}

int frequency(char note) 
{  
  int i;
  int numNotes = 8;  //number of notes we're storing (cdefgabC)

  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int frequencies[] = {262, 294, 330, 349, 392, 440, 494, 523};
  
  for (i = 0; i < numNotes; i++)  //Step through the notes
  {
    if (names[i] == note)         //check which note it is
    {
      return(frequencies[i]);     //Return frequency of that note
    }
  }
  return(0);
}
