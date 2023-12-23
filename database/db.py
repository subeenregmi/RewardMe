import mysql.connector 
import jsonschema
import json
import logging
import json_utils

def createConfigFile():
	file = open("config.json", "w")
	file.write(json.dumps({"db_host":"", "db_username":"", "db_password":""}, indent=4))
	file.close()
	logging.info("Created config.json file")

def connectToDB(h, usern, passw):
	try:
		mydb = mysql.connector.connect(
		  host=h,
		  username=usern,
		  password=passw
		)
		logging.info("Connection to database has been successful.")
		return mydb
	except:
		logging.critical("Database credentials are incorrect.")
		return None

def main():

	# config.json format
	schema = {
		"type":"object",
		"properties": {
			"db_host": {"type":"string"},
			"db_username" : {"type":"string"},
			"db_password" : {"type":"string"}
		},
		"required" : ["db_host", "db_username", "db_password"]
	}

	config = json_utils.tryReadFile("config.json")

	# if config.json not found in current directory
	if config is None:
		print("A config file was not detected!")
		userInput = input("Enter (Y) to create a new config.json: ")
		if userInput.upper() == "Y":
			createConfigFile()
		return

	config = json_utils.tryParseJson(config)

	# if config.json does not have a valid json format	
	if config is None:
		print("Config file is not in the correct format.")
		userInput = input("Enter (Y) to create a new config.json: ")
		if userInput.upper() == "Y":
			createConfigFile()
		return
	
	validJson = json_utils.validateJson(schema, config)

	# if config.json does not meet the requirements of the schematic of config.json
	if not validJson:
		print("config.json is not in the correct format.")
		userInput = input("Enter (Y) to create a new config.json: ")
		if userInput.upper() == "Y":
			createConfigFile()
		return

	hostname = config["db_host"]	
	username = config["db_username"]
	password = config["db_password"]
	
	db = connectToDB(hostname, username, password)
	
	if db is None:
		print("Database credentials are not correct")
		return 
	
if __name__ == "__main__":
	logging.basicConfig(
		filename="database.log", 
		encoding="utf-8",
		level=logging.INFO,
		format="%(asctime)s | %(levelname)s | %(message)s",
		datefmt="%d/%m/%y %H:%M:%S"
	)

	logging.info("-"*25)
	logging.info("Database script is starting.")
	main()
	logging.info("Database script is closing.")
