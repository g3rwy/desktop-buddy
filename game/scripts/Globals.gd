extends Node

var pet_name : String = "Tux"

# TODO probably a good idea to use group signal for it
func change_pet_name(s :String ) -> void:
	pet_name = s
	get_tree().current_scene.get_node("PetName").text = s

var pet_spritesheet 
var data : String

func load_data(filename : String):
	if FileAccess.file_exists(filename):
		var data_file = FileAccess.open(filename, FileAccess.READ)
		data = data_file.get_as_text()
		load_animation(data)
	else:
		print("File {} does not exist" % [filename])

func load_animation(json_string: String):
	var json = JSON.parse_string(json_string)
	print(json["path"])
