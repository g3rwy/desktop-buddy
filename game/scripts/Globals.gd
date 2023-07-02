extends Node

var pet_name : String = "Tux"

# TODO probably a good idea to use group signal for it
func change_pet_name(s :String ) -> void:
	pet_name = s
	get_tree().current_scene.get_node("PetName").text = s

var pet_spritesheet : Image
var pet_texture

var data : String

func load_data(filename : String):
	if FileAccess.file_exists(filename):
		var data_file = FileAccess.open(filename, FileAccess.READ)
		data = data_file.get_as_text()
		var end = filename.rfind("/")
		print(filename.substr(0,end))
		load_sheet(data, filename.substr(0,end) + "/")
	else:
		print("File {} does not exist" % [filename])

func load_sheet(json_string: String, base_path : String):
	var json = JSON.parse_string(json_string) 
	# TODO check if file in path exists
	# TODO do check for every field in json
	json["path"] = base_path + json["path"]
	print(json["path"])
	pet_spritesheet = Image.load_from_file( json["path"] )
	
	pet_texture = ImageTexture.create_from_image(pet_spritesheet)
	
	var pet : AnimatedSprite2D = get_tree().current_scene.get_node("Pet")
	pet.sprite_frames = SpriteFrames.new()
	pet.scale = Vector2(json["scale"],json["scale"])
	
	for anim in json["data"]:
		var frame_duration: float = 1 / json["speed"]
		
		pet.sprite_frames.add_animation(anim)
		for i in range( int(json["data"][anim]["frames"]) ):
			var frame_texture = AtlasTexture.new()
			frame_texture.atlas = pet_texture
			frame_texture.region = Rect2( 
				(json["data"][anim]["x_offset"] * json["width"]) + json["width"] * i,
				json["data"][anim]["y_offset"] * json["height"],
				json["width"],
				json["height"]
			)
			pet.sprite_frames.add_frame(anim,frame_texture,frame_duration)
	pet.play("idle")
