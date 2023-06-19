extends Control

func _ready() -> void:
	get_viewport().transparent_bg = true
	get_tree().set_auto_accept_quit(false)
	
func _input(event):
	if event.is_action_pressed("ui_cancel"):
		TrayThread.destroy_thread()
		get_tree().get_root().propagate_notification(NOTIFICATION_WM_CLOSE_REQUEST)

func _notification(what: int) -> void:
	if what == NOTIFICATION_WM_CLOSE_REQUEST:
		TrayThread.destroy_thread()
		await get_tree().process_frame
		await get_tree().process_frame
		get_tree().quit()


func _on_minimize_pressed():
	DisplayServer.window_set_mode(DisplayServer.WINDOW_MODE_MINIMIZED)
