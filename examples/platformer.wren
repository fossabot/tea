import "tea/graphics" for Graphics, Texture
import "tea/input" for Keys

class Player {
    construct new() {
        _x = 100
        _y = 500
        _vy = 0
    }
    
    update(delta) {
        _vy = _vy + delta * -700
        _y = _y + _vy * delta

        if (_y < 100) {
            _y = 100
            _vy = 0
        }

        if (Keys.is_pressed(Keys.space)) {
            _vy = 400
        }
        
        if (Keys.is_down(Keys.left)) _x = _x - delta * 300 // left
        if (Keys.is_down(Keys.right)) _x = _x + delta * 300 // left
    }

    render() {
        Graphics.rect(_x, _y, 50, 50, 0xffffffff)
    }
}

class Main {
    construct init() {
        _tex = Texture.load("hello.png")
        _player = Player.new()
    }

    update(delta) {
        Graphics.setTexture(_tex)

        _player.update(delta)
        _player.render()
    }
}