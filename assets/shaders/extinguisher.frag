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
uniform sampler2D arrowtex;
uniform float time;
uniform float raisestate;
uniform vec4 tint;

const float SHAKE_INTENSITY = 0.007;
// const float SHAKE_INTENSITY = 0.000;

void main()
{
    // Texel color fetching from texture sampler

    vec2 texCoord = fragTexCoord;
    texCoord += vec2(sin(time * 5), cos(time * 5)) * SHAKE_INTENSITY;
    texCoord *= vec2(5, 3);
    texCoord += vec2(0.25, 0);

    // NOTE: Implement here your fragment shader code
    texCoord += vec2(0, raisestate);
    vec4 texelColor = texture(texture1, texCoord);

    texelColor.a = 0;

    if (
        texCoord.x < 5
        && texCoord.x > 4
        && texCoord.y > 2
        && texCoord.y < 3
    ) texelColor = texture(texture1, texCoord);

    // Arrow overlay
    texCoord.x = texCoord.x * 1.5 - 0.07;
    texCoord.y = texCoord.y * 2.5 + 0.7;
    // texelColor.a = 0;

    if ((
        raisestate > 0.066
        && texCoord.x < 7
        && texCoord.x > 6
        && texCoord.y > 5
        && texCoord.y < 6
    )) texelColor = texture(arrowtex, texCoord);

    // final color is the color from the texture 
    //    times the tint color (colDiffuse)
    //    times the fragment color (interpolated vertex color)
    finalColor = texelColor * tint;
}
