from PIL import Image

img = Image.open("sena.png").convert("RGB")
img = img.resize((640, 480))

with open("sena.hex", "w") as f:
    for x in range(640):
        for y in range(512):
            if y < 480:
                r, g, b = img.getpixel((x, y))
                pixel = (r << 16) | (g << 8) | b
            else:
                pixel = 0x000000

            f.write(f"{pixel:06X}\n")