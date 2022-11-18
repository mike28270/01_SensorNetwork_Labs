import de.bezier.data.sql.*; 

MySQL db;

int temperature;
int did;

void setup () 
{
  frameRate(1); // 1 frame per second 
  size(200, 200);
  
  String server = "10.50.202.242"; 
  String user = "user04";
  String pass = "user04";
  String database = "user04";
  
  db = new MySQL(this, server, database, user, pass); 
  
}

void draw(){ 
if (db.connect()) {
  db.query("SELECT temperature FROM temperature ORDER BY rid DESC LIMIT 3");
    while(db.next()){
    // 1 frame per second
    temperature = db.getInt("temperature"); //get the ingeter value of the column "temperature"
    println(temperature);
    } 
  }
}
