$().ready(function () {
    $('#calcular').click(calcular);
    $('#calcular2').click(calcular2);
});


function calcular() {
    alt_gelo = $("#tempgelh").val();
    alt_ebulicao = $("#tempebuh").val();
    alt_x = $("#tempxh").val();
    
    temp = (100*(alt_x - alt_gelo)/(alt_ebulicao - alt_gelo))

    $("#temp").html(temp);
}

function calcular2() {
    alt_gelo = $("#tempgelh").val();
    alt_gelo = parseFloat(alt_gelo)
    alt_ebulicao = $("#tempebuh").val();
    alt_ebulicao = parseFloat(alt_ebulicao)
    temp_x = $("#tempx").val()
    temp_x = parseFloat(temp_x)
    
    alt = temp_x * (alt_ebulicao - alt_gelo)/100 + alt_gelo

    $("#alt").html(alt);
}