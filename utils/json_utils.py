import json 
import jsonschema
import logging

def tryReadFile(filename):
	try:
		f = open(f"{filename}", "r")
		logging.info(f"Successfully read file: {filename}")
		return f
	except IOError:
		logging.critical(f"Cannot open/find: {filename}")
		return None

def tryParseJson(fileObj):
	try:
		js = json.load(fileObj)
		logging.info("Successfully parsed json file.")
		return js
	except:
		logging.critical("Failed to parse json file.")
		return None
	
def validateJson(sch, json):
	try:
		jsonschema.validate(instance=json, schema=sch)
		logging.info("Json file has been validated against schema.")
		return True
	except jsonschema.expections.ValidateError:
		logging.critical("Json file's format is incorrect.")
		return False
