extends Node

var pet_name : String = "Tux"

# TODO probably a good idea to use group signal for it
func change_pet_name(s :String ) -> void:
	pet_name = s
	get_tree().current_scene.get_node("PetName").text = s
