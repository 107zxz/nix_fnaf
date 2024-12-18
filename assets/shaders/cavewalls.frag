#version 330

// Input vertex attributes (from vertex shader)
in vec2 fragTexCoord;
in vec4 fragColor;

// Input uniform values
uniform sampler2D texture0;
uniform vec4 colDiffuse;

// Output fragment color
out vec4 finalColor;

// NOTE: Add here your custom variables
uniform sampler2D texture1;
uniform float time;
uniform vec4 tint;

uniform vec2 mouse;

const float PI = 3.14159265;
 
void main()
{
    // Texel color fetching from texture sampler
    vec2 texCoord = fragTexCoord;
    texCoord += vec2(0, time/3);

    if (texCoord.x <0 || texCoord.x > 1) { texCoord.x = -texCoord.x; }

    vec4 texelColor = texture(texture1, texCoord);


    // NOTE: Implement here your fragment shader code

    float darkness = 1 - cos(texCoord.x * PI * 5/2 - PI/4);
    darkness *= 0.3;

    // darkness = abs(mouse.x - texCoord.x);

    vec4 shadow = vec4(darkness, darkness, darkness, 0);

    texelColor -= shadow;


    // final color is the color from the texture 
    //    times the tint color (colDiffuse)
    //    times the fragment color (interpolated vertex color)
    finalColor = texelColor * tint;
}
