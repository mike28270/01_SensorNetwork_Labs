import de.bezier.data.sql.*; 

MySQL db;

void setup () 
{
  frameRate(1); // 1 frame per second 
  size(200, 200);
  
  String server = "10.50.202.242"; 
  String user = "user04";
  String pass = "user04";
  String database = "user04";
  
  db = new MySQL(this, server, database, user, pass); 
  if (db.connect()) {
    db.query("INSERT INTO temperature(did, date, time, temperature) VALUES(1, CURRENT_DATE(), CURRENT_TIME(),24)");
  } 
}

void draw(){ }
