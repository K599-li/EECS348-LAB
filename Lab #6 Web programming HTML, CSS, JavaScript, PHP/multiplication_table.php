<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Multiplication Table</title>
    <style>
        table, th, td {
            border: 1px solid black;
            border-collapse: collapse;
            text-align: center;
            padding: 5px;
        }
    </style>
</head>
<body>
    <form method="post">
        <label for="number">Size of the multiplication table:</label>
        <input type="number" id="number" name="number" min="1" required>
        <input type="submit" value="Generate Table">
    </form>

    <?php
    if ($_SERVER['REQUEST_METHOD'] === 'POST') {
        $number = intval($_POST['number']);

        echo "<h3>Multiplication Table from 1 to $number</h3>";
        echo "<table>";

        // Print column indexes
        echo "<tr><th></th>";
        for ($i = 1; $i <= $number; $i++) {
            echo "<th>$i</th>";
        }
        echo "</tr>";

        // Print rows with multiplication values
        for ($i = 1; $i <= $number; $i++) {
            echo "<tr>";
            echo "<th>$i</th>"; // Row index
            for ($j = 1; $j <= $number; $j++) {
                echo "<td>" . ($i * $j) . "</td>";
            }
            echo "</tr>";
        }

        echo "</table>";
    }
    ?>
</body>
</html>
