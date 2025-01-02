H, M = map(int, input().split())
angle = (60.0 * H - 11.0 * M) / 2.0
if angle > 180.0:
	angle = 360.000 - angle;

print(angle)