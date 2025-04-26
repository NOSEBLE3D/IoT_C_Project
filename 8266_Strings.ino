char default_database[] = "wittest";           
char table2[] = "powercurrent";          

int powerStatusCurrent = 0;
int powerStatusLast = 0;
char cid[] = "10000000";
char when[] = "now()";

// Query build
char INSERT_SQL[100]; // Declare a character array to store the INSERT SQL query
char UPDATE_SQL[100]; // Declare a character array to store the UPDATE SQL query
  
void setup() {
  Serial.begin(115200);   
}

void loop() {
  // Build INSERT SQL query
  sprintf(INSERT_SQL, "INSERT INTO %s.%s (currentStatus, sinceWhen, complexCid) VALUES (%d, %s, %s)", 
          default_database, table2, powerStatusCurrent, when, cid);
  
  // Build UPDATE SQL query
  sprintf(UPDATE_SQL, "UPDATE %s.%s SET currentStatus = %d, sinceWhen = %s WHERE complexCid = %s", 
          default_database, table2, powerStatusCurrent, when, cid);
  
  // Print SQL queries
  Serial.println(INSERT_SQL);
  Serial.println(UPDATE_SQL);
  
  delay(2000);   // Wait 2 seconds  
}
