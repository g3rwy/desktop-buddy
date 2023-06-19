extends MenuButton

var pop_up
var change_name : LineEdit

func _ready() -> void:
	pop_up = get_popup()
	pop_up.connect("id_pressed",_on_id_pressed)

func _on_id_pressed(id: int) -> void:
	match(id):
		0: # Change name of Pet
			var anim_name = Popup.new() 
			anim_name.connect("close_requested",_on_popup_closed)
			anim_name.connect("focus_exited",_on_popup_closed)
			anim_name.size = Vector2i(200,200)
			
			change_name = LineEdit.new()
			change_name.text = Globals.pet_name
			change_name.set_anchors_and_offsets_preset(Control.PRESET_CENTER)
			change_name.size.x = 150
			change_name.position.x = -75 
			
			get_tree().get_root().add_child(anim_name)
			anim_name.add_child(change_name)
			var button = Button.new()
			
			button.connect("pressed",func(): anim_name.hide())
				
			button.text = "CHANGE"
			button.set_anchors_and_offsets_preset(Control.PRESET_CENTER)
			button.position.y += change_name.size.y 
			anim_name.add_child(button)
			
			anim_name.show()
		_:
			print("WHAT")

func _on_popup_closed() -> void:
	var new_name = change_name.text.lstrip(" \t")
	if new_name.is_empty():
		Globals.change_pet_name("Tux")
	else:
		Globals.change_pet_name(new_name.rstrip(" \t"))

