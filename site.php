<!-- Run php -S localhost:4000 to set up the webserver on localhost,
then put localhost+fileroot in the browser heading-->
<html>
    <head>
        <title>PHP Site</title>
    </head>
        <h1>PHP Site</h1>
        <p>
            <!-- These are special html tags, using $_POST is more secure than $_GET -->
            <?php
                $namer = $_POST["private"];
                $integerAge = 25;
                $booleanIsStudent = false;
                echo "Hello, $namer!";
                echo "<hr>";
                echo "Welcome to the $integerAge website, $booleanIsStudent";
            ?>
        </p>
        <form action="site.php" method="post">
            privateName: <input type="text" name="private">
            <input type="submit">
    </body>
</html>