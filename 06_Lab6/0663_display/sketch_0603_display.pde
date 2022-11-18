import de.bezier.data.sql.*; 

MySQL db;

int lf = 10;
int temperature;
int did;

void setup () 
{
  frameRate(1); // 1 frame per second 
  size(330,306);
  
  String server = "10.50.202.242"; 
  String user = "user04";
  String pass = "user04";
  String database = "user04";
  
  db = new MySQL(this, server, database, user, pass); 
  
}

void draw(){ 
  int i;
  int ypos;
  if (db.connect()) {
    db.query("SELECT temperature FROM temperature ORDER BY rid DESC LIMIT 3");
      while(db.next()){
      // 1 frame per second
      temperature = db.getInt("temperature"); //get the ingeter value of the column "temperature"
      println(temperature);
      } 
    }
  ypos = int((100 - float(temperature)) / 100 * 256); 
  background(32);
  for(i=0; i<256; i++) {
    stroke(255 - i, 128, i);
    line(25, 25+i, 175, 25+i); }
  stroke(255);
  for ( i = 0 ; i < 11 ; i++) {
  int ypos2 = round(25+25.6*i);
  line(173 , ypos2, 177, ypos2+6);
  textSize(12);
  text(((10-i)*10), 178, ypos2+6); 
  }
  
  stroke(255, 128); 
  line(20,25+ypos, 205, 25+ypos);
  textSize(32);
  text(temperature , 205, ypos+38);
}
