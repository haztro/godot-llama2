extends Control

var thread: Thread = null
var tween: Tween = null

@onready var button: Button = $VBoxContainer/Button
@onready var text: Label = $VBoxContainer/Label
@onready var progress_ring: TextureProgressBar = $VBoxContainer/TextureProgressBar


# Called when the node enters the scene tree for the first time.
func _ready():
	thread = Thread.new()
	tween = get_tree().create_tween().set_loops()
	tween.tween_property(progress_ring, "radial_initial_angle", 360.0, 1.5)


func _run_model():
	var l = Llama2.new()
	var result: String = l.run("stories110M.bin", 1.0, 0.9, 256, "Once upon a time", 0, "generate", "", "tokenizer.bin")
	call_deferred("_model_finished")
	return result
	

func _model_finished():
	text.text = thread.wait_to_finish()
	tween.stop()
	progress_ring.visible = false
	text.visible = true
	button.disabled = false


func _on_button_pressed():
	tween.play()
	progress_ring.visible = true
	text.visible = false
	button.disabled = true
	thread.start(_run_model)


