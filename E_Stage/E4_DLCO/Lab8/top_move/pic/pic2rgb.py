from PIL import Image

img = Image.open("ysyx.png").convert("RGB")
img = img.resize((100, 100))

with open("ysyx.hex", "w") as f:
    for x in range(640):
        for y in range(512):
            if x < 100 and y < 100:
                r, g, b = img.getpixel((x, y))
                pixel = (r << 16) | (g << 8) | b
            else:
                pixel = 0xFFFFFF
            f.write(f"{pixel:06X}\n")
