<html>
<body>

  <?php
  $servername ="10.50.202.242"; // the IP address of your server
  $username = "user04"; // your user name to access the database
  $password = "user04"; // your password to access the database
  $dbname = "user04"; // the database which is already created on the server
  $conn = new mysqli( $servername , $username , $password , $dbname ); //set up connection to the database on the server
  if ( $conn->connect_error ) { // print out the error message if connection fails
    die ( "Connection failed : ".$conn->connect_error );
  }
  else{echo "Database connection is successful.";} // print out the successful message if connection is successful.

  $sql = "CREATE TABLE IF NOT EXISTS LED(rid SERIAL, did INT, date DATE , time TIME, state CHAR)"; // create a table called temperature
  if ($conn->query($sql) === TRUE) { //use this SQL to query the databse
      echo "New table created successfully";
  } else {
  echo "Error: " . $sql . "<br>" . $conn->error; // print out the error
  //message if the query fails
  }

  //$sql = "INSERT INTO led(did, date, time, state) VALUES(1, CURRENT_DATE(), CURRENT_TIME(), 'n')"; // insert data into temperature table
  //if ($conn ->query($sql) === TRUE) {
  //    echo "New record created successfully";
  //} else {
  //echo "Error: " . $sql . "<br>" . $conn->error;
  //}

  $sql = "SELECT * FROM led ORDER BY rid DESC LIMIT 10"; // create a table called temperature
  $result = $conn->query($sql);
  if ($result ->num_rows > 0) { //use this SQL to query the databse
    echo "<html><body><table border=’1’>"; // output table in HTML
    echo "<tr><td>Device ID</td><td>Date</td><td>Time</td><td>State </td></tr>";
    while($row = $result->fetch_assoc()) { //$row contains the next record in $result
      $deviceID = $row["did"]; // $deviceID contains the value in the "did" column
      $date = $row["date"]; // $date contains the value in the "date" column
      $time = $row["time"]; // $time contains the value in the "time"
      $state = $row["state"]; // $temperature contains the column value in the "temperature" column
      echo "<tr><td>$deviceID </td><td>$date </td><td>$time </td><td> $state</td></tr>";
    }
    echo "</table></body></html>";
  } else {
  echo "0 result."; // print out the error
  //message if the query fails
  }

  $conn->close(); // close the connection

  ?>

  <form action='led_action.php'>
    <fieldset>
      <legend>LED state:</legend>
      <input type="radio" name="status" value="n" checked> On<br>
      <input type="radio" name="status" value="f"> Off<br>
      <input type="radio" name="status" value="b"> Blink
      <input type="submit">
    </fieldset>
  </form>



</body>
</html>
