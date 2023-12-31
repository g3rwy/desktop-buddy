extends Node

var tray_thread : Thread
var tray_ref : VirtualPet


func _init() -> void:
	tray_ref = VirtualPet.new()
	tray_thread = Thread.new()
	tray_thread.start(tray_ref._start_tray)
	
	tray_ref.connect("close_window", func (): get_tree().get_root().propagate_notification(NOTIFICATION_WM_CLOSE_REQUEST) )


func destroy_thread():
	tray_ref.set_stop_tray(true)
	
	# FIXME, Does it matter if i wait for it?
	#tray_thread.wait_to_finish()
