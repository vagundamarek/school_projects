from PIL import Image

def average_alpha(a1, a2):
    return ((a1+a2)/2)

def average_color(c1, c2, a1, a2, k):
    return (c1*a1*(1-k) + c2*a2*k)/average_alpha(a1, a2)

def average_pixel(p1, p2, k):
    p=[]
    for i in range(0, 3):
        p.append(int(average_color(p1[i], p2[i], p1[3], p2[3], k)))
    p.append(int(average_alpha(p1[3], p2[3])))

    return (p[0], p[1], p[2], p[3])

def blend (top_image, bottom_image):
    if top_image.size != bottom_image.size:
        print("Size of img1 is different from size of img 2")
        return
    img1 = top_image.convert("RGBA")
    img2 = bottom_image.convert("RGBA")
    
    w, h = img1.size    
    out = Image.new("RGBA", (w, h))
    
    for y in range (0, h):
        for x in range (0, w):
            out.putpixel((x,y),average_pixel(img1.getpixel((x, y)), img2.getpixel((x, y)), y/h))

    out.save("result.png")


